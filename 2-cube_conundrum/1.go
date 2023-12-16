package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func checkPossible(number int, color string) bool {
    switch color {
    case "red":
        return number <= 12
    case "green":
        return number <= 13
    case "blue":
        return number <= 14
    }
    return false
}

func main(){
    f, err := os.Open("/home/noah/aoc/2-cube_conundrum/input")
    if (err != nil) {
        panic(err)
    }
    defer f.Close()

    scanner := bufio.NewScanner(f)
    ans := 0
    for scanner.Scan(){
        line := strings.Split(scanner.Text(), ":")
        input := strings.TrimSpace(line[1])
        gamenumber, err := strconv.Atoi(strings.Split(line[0], " ")[1])
        if err != nil {
            panic(err)
        }
        values := strings.Split(input, "; ")
        possible := true
        for _, v := range values {
            counts := strings.Split(strings.TrimSpace(v), ", ")
            for _, c := range counts {
                pair := strings.Split(c, " ")
                number, err := strconv.Atoi(pair[0])
                if err != nil {
                    panic(err)
                }
                color := pair[1];
                possible = possible && checkPossible(number, color)
            }
        }
        if possible {
            ans += gamenumber
            fmt.Println(gamenumber, ans)
        }
    }
}
