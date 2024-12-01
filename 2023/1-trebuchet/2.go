package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main(){
    f, err := os.Open("/home/noah/aoc/1-trebuchet/input")
    if (err != nil) {
        panic(err)
    }
    defer f.Close()

    ans := 0

    scanner := bufio.NewScanner(f)
    for scanner.Scan(){
            line := scanner.Text()
            line = strings.ReplaceAll(line, "one", "one1one")
            line = strings.ReplaceAll(line, "two", "two2two")
            line = strings.ReplaceAll(line, "three", "three3three")
            line = strings.ReplaceAll(line, "four", "four4four")
            line = strings.ReplaceAll(line, "five", "five5five")
            line = strings.ReplaceAll(line, "six", "six6six")
            line = strings.ReplaceAll(line, "seven", "seven7seven")
            line = strings.ReplaceAll(line, "eight", "eight8eight")
            line = strings.ReplaceAll(line, "nine", "nine9nine")
            fmt.Println(line)
            s := strings.Split(line, "")
            var digits []int
            for _, v := range s {
                if d, err := strconv.Atoi(v); err == nil {
                    digits = append(digits, d)
                }
            }
            if len(digits) > 0 {
                score := int((digits[0] * 10)+digits[len(digits)-1])
                ans += score
            }
    }
    fmt.Println(ans)
}
