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
            s := strings.Split(scanner.Text(), "")
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
