import os


# Open file and read content
def read_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    return content


def rotate_lock(state, direction, distance, count):
    tmp_state = state

    if state == 0 and direction == 'R':
        count += 1
    
    if direction == 'L':
        tmp_state = state - distance
    elif direction == 'R':
        tmp_state = state + distance

    wraps = abs(tmp_state // 100)
    print(f"{direction}{distance} from state {state} -> WRAPS: {wraps}")

    count += wraps
    state = tmp_state % 100


    return state, count


def main():
    #puzzle_path = "test.txt"
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
        state, count = rotate_lock(state, dir, dist, count)
        if state == 0 and dir == 'R':
            count -= 1
        print(state)

    print("---")
    print(count)


if __name__ == "__main__":
    main()
