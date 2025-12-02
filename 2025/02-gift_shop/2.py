import os

def read_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    return content


def check_range(start, end):
    sum = 0
    for i in range(start, end + 1):
        str_num = str(i)
#       print("CHECKING", str_num)
#       print("LENGTH", len(str_num))

        for x in range(1, len(str_num)):
            partitions = []
            for y in range(0, len(str_num), x):
                part = str_num[y:y+x]
                partitions.append(part)

#           print("PARTITIONS")
#           print(partitions)

            if len(partitions) > 1:
                if all(part == partitions[0] for part in partitions):
                    print("MATCH:", str_num)
                    sum += i
                    break

    return sum


def main():
    #puzzle_path = "sample.txt"
    #puzzle_path = "test.txt"
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
