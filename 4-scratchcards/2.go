package main

import (
	"fmt"
	"io/ioutil"
	"strings"
)

type card struct{
    amount int
    left string
    right []string
}

func getPoints(left string, right []string) int {
    winning := strings.Split(left, " ")
    points := 0
    for _, v := range right {
        if v == "" || v == " " {
            continue
        }
        for _, v2 := range winning {
            if v2 == v {
                points += 1
            }
        }
    }
    return points
}

func main() {
    f, err := ioutil.ReadFile("/home/joker/aoc/4-scratchcards/input") 
    if err != nil {
        panic(err)
    }

    lines := strings.Split(string(f), "\n")

    var cards []card
    total := 0

    for idx, line := range lines {
        if line == "" || idx == len(lines)-1 {
            continue
        }

        content := strings.Split(strings.Split(line, ": ")[1], " | ")
        left := content[0]
        right := strings.Split(content[1], " ")

        if len(cards) >= idx+1  {
            if cards[idx].left == "" {
                cards[idx].left = left
                cards[idx].right = right
                cards[idx].amount += 1
            } 
        } else {
            cards = append(cards, card{left: left, right: right, amount: 1}) 
        }
        points := getPoints(cards[idx].left, cards[idx].right) 
        for i := 1; i <= points; i++ {
            if len(cards) < idx+i+2 {
                cards = append(cards, card{})
            }
            cards[idx+i].amount += cards[idx].amount
        }
    }
    for _, c := range cards {
        total += c.amount 
    }
    fmt.Println(total)
}

