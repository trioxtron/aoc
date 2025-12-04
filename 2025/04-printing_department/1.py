import os


def read_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    return content


def check_paper(y, x, map) -> int:
    y_len = len(map)
    x_len = len(map[0])
    if x < 0 or y < 0 or x >= x_len or y >= y_len:
        return 0

    if map[y][x] == "@":
        return 1

    return 0


def check_map(map):
    dirs = [
        (-1, 0),
        (-1, 1),
        (0, 1),
        (1, 1),
        (1, 0),
        (1, -1),
        (0, -1),
        (-1, -1)
    ]

    res = 0

    for y in range(len(map)):
        for x in range(len(map[0])):
            if map[y][x] != "@":
                continue
            sum = 0

            for dir in dirs:
                sum += check_paper(y + dir[0], x + dir[1], map)

            if sum < 4:
                res += 1

    print(res)


def main():
    #puzzle_path = "sample.txt"
    puzzle_path = "puzzle.txt"
    if not os.path.exists(puzzle_path):
        return

    content = read_file(puzzle_path)
    print("File Content:")
    print(content)
    lines = content.splitlines()

    map = []

    for line in lines:
        row = []
        for char in line:
            row.append(char)
        map.append(row)

    print(check_map(map))




if __name__ == "__main__":
    main()
