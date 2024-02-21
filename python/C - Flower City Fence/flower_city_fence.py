import sys


def is_symmetrical(planks, heights):
    blocks = []
    length = 0
    images = []
    k = 1
    prev = heights[0]
    for j in range(1, planks):
        if heights[j] == prev:
            k += 1
        else:
            blocks.append([prev, k])
            length += 1
            prev = heights[j]
            k = 1
    blocks.append([prev, k])
    length += 1
    if length == 1:
        if blocks[0][1] == blocks[0][0]:
            return True
        else:
            return False
    else:
        images.append([blocks[0][1], blocks[0][0] - blocks[1][0]])

    for r in range(1, length):
        if r == length - 1:
            new_height = images[-1][0] + blocks[r][1]
            new_width = blocks[r][0]
        else:
            new_height = images[-1][0] + blocks[r][1]
            new_width = blocks[r][0] - blocks[r+1][0]

        images.append([new_height, new_width])

    images.reverse()
    return blocks == images

if __name__ == '__main__':
    data = sys.stdin.readlines()

    for i in range(int(data[0])):
        n = int(data[i * 2 + 1])
        a = [int(k) for k in data[i * 2 + 2].rstrip().split()]

        if is_symmetrical(n, a):
            sys.stdout.write('YES\n')
        else:
            sys.stdout.write('NO\n')
