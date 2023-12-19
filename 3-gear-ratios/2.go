package main

import (
	"fmt"
	"io/ioutil"
	"strconv"
	"strings"
)

func isNumber(char rune) bool{
    return char >= 48 && char <= 57
}
func isDot(char rune) bool{
    return char == 46
}
func isSymbol(char byte) bool{
    return !isNumber(rune(char)) && !isDot(rune(char))
}
func isStar(char byte) bool{
    return char == 42
}

func check(lines []string, y, xs, xe int) (bool, int, int) {
    for i := xs; i <= xe; i++ {
        if y > 0 {
            if isStar(lines[y-1][i]) {
                return true, y-1, i
            }
        }
        if y < len(lines)-2 {
            //fmt.Println(y, len(lines))
            //fmt.Println(lines[y],y, i)
            if isStar(lines[y+1][i]) {
                return true, y+1, i
            }
        }

        //checking inline boundaries & corners
        if xs > 0 {
            if isStar(lines[y][xs-1]) {
                return true, y, xs-1
            }
            if y > 0 {
                if isStar(lines[y-1][xs-1]) {
                    return true, y-1, xs-1
                }
            }
            if y < len(lines[y])-1 {
                if isStar(lines[y+1][xs-1]){
                    return true, y+1, xs-1
                }
            }
        }
        if xe < len(lines[y])-1 {
            if isStar(lines[y][xe+1]){
                return true, y, xe+1
            }
            if y > 0 {
                if isStar(lines[y-1][xe+1]){
                    return true, y-1, xe+1
                }
            }
            if y < len(lines[y])-1 {
                if isStar(lines[y+1][xe+1]){
                    return true, y+1, xe+1
                }
            }
        }
    }
    return false, -1, -1
}

func main(){
    f, err := ioutil.ReadFile("/home/joker/aoc/3-gear-ratios/input")
    if (err != nil) {
        panic(err)
    }

    lines := strings.Split(string(f), "\n")

    toScore := make(map[string][]int) 
    score := 0

    ns := -1
    ne := -1

    for y, line := range lines {
        for x, char := range line {
            if isNumber(char){
                if ns == -1 {
                    ns = x
                }
                ne = x
            }
            if !isNumber(char) && ns != -1{
                n, err := strconv.Atoi(lines[y][ns:ne+1])
                if err != nil {
                    panic(err)
                }
                //fmt.Println(line,ns,ne)
                if positive, sy, sx := check(lines,y,ns,ne); positive {
                    toScore[fmt.Sprintf("%d,%d", sy, sx)] = append(toScore[fmt.Sprintf("%d,%d", sy, sx)], n)
                }
                ns = -1
                ne = -1
            }
        } 
        if ns != -1 {
            n, err := strconv.Atoi(lines[y][ns:ne+1])
            if err != nil {
                panic(err)
            }
            if positive, sy, sx := check(lines,y,ns,ne); positive {
                toScore[fmt.Sprintf("%d,%d", sy, sx)] = append(toScore[fmt.Sprintf("%d,%d", sy, sx)], n)
            }
            ns = -1
            ne = -1
        }
    }
    for _, v := range toScore {
        if len(v) == 2 {
            power := 1
            for _, number := range v {
                power *= number
            }
            score += power
        }
    }
    fmt.Println(score)
}
