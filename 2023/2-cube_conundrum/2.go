package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main(){
    f, err := os.Open("/home/noah/aoc/2-cube_conundrum/input")
    if (err != nil) {
        panic(err)
    }
    defer f.Close()

    scanner := bufio.NewScanner(f)
    ans := 0
    for scanner.Scan(){
        input := strings.TrimSpace(strings.Split(scanner.Text(), ":")[1])
        values := strings.Split(input, "; ")
        red := 0
        green := 0
        blue := 0
        for _, v := range values {
            counts := strings.Split(strings.TrimSpace(v), ", ")
            for _, c := range counts {
                pair := strings.Split(c, " ")
                number, err := strconv.Atoi(pair[0])
                if err != nil {
                    panic(err)
                }
                switch color := pair[1]; color {
                case "red":
                    if number > red {
                        red = number
                    }
                case "green":
                    if number > green {
                        green = number
                    }
                case "blue":
                    if number > blue {
                        blue = number
                    }
                }
            }
        }
        power := red * green * blue
        fmt.Println(power)
        ans += power
    }
    fmt.Println(ans)
}
