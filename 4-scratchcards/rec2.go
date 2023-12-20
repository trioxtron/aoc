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

func getPoints(line string, idx int) []int {
    var copies []int

    points := 0
    content := strings.Split(strings.Split(line, ": ")[1], " | ") 
    winners := strings.Split(strings.TrimSpace(content[0]) , " ")
    numbers := strings.Split(strings.TrimSpace(content[1]) , " ")

    for _, number := range numbers {
        num := strings.TrimSpace(number)
        if contains(winners, num) {
            points++
        }
    }
    for i := 0; i < points; i++ {
        copies = append(copies, idx+i)
    }
    
    fmt.Println(copies)
    return copies
}

func recursion(lines []string, idx, ans int, points []int) int {
    if idx == len(lines)-2{
        return 1
    }
    for _, v := range points {
        fmt.Println(v)
       return ans + recursion(lines, idx+1, ans, getPoints(lines[idx], v)) 
    }
    return 0
}

func main(){
    f, err := ioutil.ReadFile("/home/joker/aoc/4-scratchcards/input_test")
    if (err != nil) {
        panic(err)
    }

    lines := strings.Split(string(f), "\n")

    ans := 0

    for idx, line := range lines {
        if line == ""{
            return 
        }
        fmt.Println(idx)
        ans += recursion(lines, idx, 1, getPoints(line, idx+2))
        //fmt.Println(ans)
    }
}
