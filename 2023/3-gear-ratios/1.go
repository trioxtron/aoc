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

func check(lines []string, y, xs, xe int) bool {
    for i := xs; i <= xe; i++ {
        //if xs < 0 || xe > len(lines[y]){
            //fmt.Println("bananarama")
        //    return false
        //}
        //checking upper and lower line boundaries
        if y > 0 {
            if isSymbol(lines[y-1][i]) {
                return true
            }
        }
        if y < len(lines)-2 {
            //fmt.Println(y, len(lines))
            //fmt.Println(lines[y],y, i)
            if isSymbol(lines[y+1][i]) {
                return true
            }
        }

        //checking inline boundaries & corners
        if xs > 0 {
            if isSymbol(lines[y][xs-1]) {
                return true
            }
            if y > 0 {
                if isSymbol(lines[y-1][xs-1]) {
                    return true
                }
            }
            if y < len(lines[y])-1 {
                if isSymbol(lines[y+1][xs-1]){
                    return true
                }
            }
        }
        if xe < len(lines[y])-1 {
            if isSymbol(lines[y][xe+1]){
                return true
            }
            if y > 0 {
                if isSymbol(lines[y-1][xe+1]){
                    return true
                }
            }
            if y < len(lines[y])-1 {
                if isSymbol(lines[y+1][xe+1]){
                    return true
                }
            }
        }
    }
    return false
}

func main(){
    f, err := ioutil.ReadFile("/home/joker/aoc/3-gear-ratios/input")
    if (err != nil) {
        panic(err)
    }

    lines := strings.Split(string(f), "\n")
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
                if check(lines,y,ns,ne) {
                    fmt.Println(line)
                    fmt.Println(lines[y][ns:ne+1])
                    score += n
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
            if check(lines,y,ns,ne) {
                fmt.Println()
                fmt.Println(lines[y][ns:ne+1])
                score += n
            }
            ns = -1
            ne = -1
        }
    }
    fmt.Println(score)
}
