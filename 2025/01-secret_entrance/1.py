import os


# Open file and read content
def read_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    return content


def rotate_lock(state, direction, distance):
    if direction == 'L':
        state = (state - distance) % 100
    elif direction == 'R':
        state = (state + distance) % 100 
    return state


def main():
    #puzzle_path = "sample.txt"
    puzzle_path = "puzzle.txt"
    if not os.path.exists(puzzle_path):
        return

    content = read_file(puzzle_path)
    print("File Content:")
    print(content)
    lines = content.splitlines()

    state = 50
    count = 0

    for line in lines:
        dir = line[0]
        dist = int(line[1:])
        state = rotate_lock(state, dir, dist)

        if state == 0:
            count += 1

    print(count)

if __name__ == "__main__":
    main()
