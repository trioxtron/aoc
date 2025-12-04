import os

def read_file(file_path):
    with open(file_path, 'r') as file:
        content = file.read()
    return content


def find_biggest(nums):
    spot = 0
    num = 0

    for i, x in enumerate(nums):
        if x > num:
            num = x
            spot = i

    return num, spot


def extract_biggest(line):
    nums = [int(x) for x in line]
    res = 0
    #print(nums)

    for i in range(12, 0, -1):
        left_idx = len(nums) - i + 1
        #print("Nums: ", nums)
        #print(f"Available ({i}): ", nums[:left_idx])
        num, spot = find_biggest(nums[:left_idx])
        res *= 10 
        res += num
        nums = nums[spot+1:]

    return res


def main():
    #puzzle_path = "sample.txt"
    puzzle_path = "puzzle.txt"
    if not os.path.exists(puzzle_path):
        return

    content = read_file(puzzle_path)
    #print("File Content:")
    #print(content)
    lines = content.splitlines()

    sum = 0

    for line in lines:
        num = extract_biggest(line)
        sum += num

    print(sum)




if __name__ == "__main__":
    main()
