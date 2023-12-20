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
        num = strings.Trim(number, " ")
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

func checkContain(lists [][]int, items []int) bool {
    for _, list := range lists {
        if len(list) != len(items) {
            return false
        }
        for i, list_item := range list {
           if list_item != items[i] {
               return false
           }
        }
    }
    return true
}

func main(){
    f, err := ioutil.ReadFile("/home/joker/aoc/4-scratchcards/input_test")
    if (err != nil) {
        panic(err)
    }

    lines := strings.Split(string(f), "\n")

    var toProcess []int
    var seen [][]int
    var count [][]int

    for idx, line := range lines {
        if line == ""{
            return 
        }
        toProcess = append(toProcess, idx+1)
    }
    for _, v := range toProcess {
        idx := toProcess[len(toProcess)-1]
        toProcess = toProcess[:len(toProcess)-1]
        if checkContain(seen, idx){

        }

    }
    fmt.Println(count)
}
