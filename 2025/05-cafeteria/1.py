import os
type Range = tuple[int, int]
type Ranges = list[Range]


def read_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    return content


def in_between(lower: int, upper: int, num:int) -> bool:
    return num >= lower and num <= upper


def check_number(ranges: Ranges, num: int) -> bool:
    for r in ranges:
        if num >= r[0]:
            check = in_between(r[0], r[1], num)
            if check:
                return True

    return False


def main():
    #puzzle_path = "sample.txt"
    puzzle_path = "puzzle.txt"
    if not os.path.exists(puzzle_path):
        return

    content = read_file(puzzle_path)
    print("File Content:")
    print(content)
    lines = content.splitlines()

    ranges: Ranges = []
    res = 0

    reading_ranges = True
    to_test = []

    for i, line in enumerate(lines):
        if line == "":
            reading_ranges = False
            continue

        if reading_ranges == True:
            curr_range = line.split("-")
            lower = int(curr_range[0])
            upper = int(curr_range[1]) + 1
            ranges.append((lower, upper))
        else: 
            to_test.append(int(line))


    print(ranges)
    ranges = sorted(ranges, key=lambda x: x[0])
    print(ranges)
    i = 0

    while i < len(ranges):
        c = ranges[i]
        n = ranges[i+1]
        if c[1] > n[0]:
            if n[1] > c[1]:
                ranges[i] = (c[0], n[1])

            ranges.pop(i+1)
            i += 1
        i += 1

    print(ranges)

    print(to_test)
    for num in to_test:
        res += check_number(ranges, num)

    print(res)


if __name__ == "__main__":
    main()
