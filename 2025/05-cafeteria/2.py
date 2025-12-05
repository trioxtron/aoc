import os
type Range = tuple[int, int]
type Ranges = list[Range]


def read_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    return content


def main():
    #puzzle_path = "sample.txt"
    #puzzle_path = "test.txt"
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
            upper = int(curr_range[1])
            ranges.append((lower, upper))
        else: 
            to_test.append(int(line))


    ranges = sorted(ranges, key=lambda x: x[0])

    i = 0
    while i < len(ranges) - 1:
        c = ranges[i]
        n = ranges[i+1]
        if c[1] >= n[0]:
            if n[1] > c[1]:
                ranges[i] = (c[0], n[1])

            ranges.pop(i+1)
        else: 
            i += 1

    for r in ranges:
        res += r[1] - r[0] + 1

    print(res)



if __name__ == "__main__":
    main()
