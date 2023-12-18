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
        if xs < 0 || xe > len(lines[y]){
            return false
        }
        //checking upper and lower line boundaries
        if y > 0 {
            if isSymbol(lines[y-1][i]) {
                return true
            }
        }
        if y < len(lines)-2 {
            fmt.Println(len(lines))
            //fmt.Println(lines[y],y, i)
            if isSymbol(lines[y+1][i]) {
                return true
            }
        }

        //checking inline boundaries & corners
        if xs > 0 {
            return isSymbol(lines[y][xs-1])
        }
        if xe < len(lines[y])-1 {
            return isSymbol(lines[y][xe+1])
        }
    }
    return false
}

func main(){
    f, err := ioutil.ReadFile("/home/noah/aoc/3-gear-ratios/input_test")
    if (err != nil) {
        panic(err)
    }

    lines := strings.Split(string(f), "\n")
    score := 0

    ns := -1
    ne := -1

    for y, line := range lines {
        if ns != -1 {
            ns = -1
            ne = -1
        }
        for x, char := range line {
            if isNumber(char){
                if ns == -1 {
                    ns = x
                }
                ne = x
            }
            if isDot(char){
                //fmt.Println(y,ns,ne)
                if check(lines,y,ns,ne) {
                    fmt.Println(lines[y][ns:ne+1])
                    n, err := strconv.Atoi(lines[y][ns:ne+1])
                    if err != nil {
                        panic(err)
                    }
                    score += n
                }
                ns = -1
                ne = -1
            }
        } 
        if ns != -1 {
            ns = -1
            ne = -1
        }
        fmt.Println(score)
    }

}
