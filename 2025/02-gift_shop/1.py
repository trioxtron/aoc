import os

def read_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    return content

def check_range(start, end):
    sum = 0
    for i in range(start, end + 1):
        if len(str(i)) % 2 != 0:
            continue

        str_num = str(i)

        first = str_num[:len(str_num)//2]
        second = str_num[len(str_num)//2:]

        if first == second:
            sum += i

    return sum



def main():
    #puzzle_path = "sample.txt"
    puzzle_path = "puzzle.txt"
    if not os.path.exists(puzzle_path):
        return

    content = read_file(puzzle_path)
    print("File Content:")
    print(content)

    ranges = content.splitlines()[0].split(",")
    #print("Ranges:", ranges)

    res = 0
    for r in ranges:
        start, end = map(int, r.split("-"))
        res += check_range(start, end)

    print("Result:", res)


if __name__ == "__main__":
    main()
