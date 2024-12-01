package main

import (
	"fmt"
	"io/ioutil"
	"strings"
)

func contains(numbers []string, num string) bool {
    if num == "" {
        return false
    }
    for _, v := range numbers {
        if num == v {
            return true
        } 
    }
    return false
}

func main(){
    f, err := ioutil.ReadFile("/home/joker/aoc/4-scratchcards/input")
    if (err != nil) {
        panic(err)
    }

    lines := strings.Split(string(f), "\n")
    score := 0

    for _, line := range lines {
        if line == ""{
            return
        }
        points := 0
        content := strings.Split(strings.Split(line, ": ")[1], " | ") 
        winners := strings.Split(strings.TrimSpace(content[0]) , " ")
        numbers := strings.Split(strings.TrimSpace(content[1]) , " ")

        for _, number := range numbers {
            num := strings.TrimSpace(number)
            if contains(winners, num) {
                if points == 0 {
                    points = 1
                } else {
                    points <<= 1
                }
            }
        }
        score += points
        fmt.Println(score)
    }
}
