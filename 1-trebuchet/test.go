package main

import (
	"fmt"
	"strings"
)

func main(){
    line := "two1nine"
    line = strings.ReplaceAll(line, "two", "two2two")
    line = strings.ReplaceAll(line, "nine", "nine9nine")

    fmt.Println(line)

}
