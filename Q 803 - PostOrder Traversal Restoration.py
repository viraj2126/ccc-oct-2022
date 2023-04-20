def printPostorder(start, end, preorder, pIndex, d):

    if start > end:
        return pIndex
    value = preorder[pIndex]
    pIndex = pIndex + 1

    if start == end:
        print(value, end="")
        return pIndex

    i = d[value]
    pIndex = printPostorder(start, i - 1, preorder, pIndex, d)
    pIndex = printPostorder(i + 1, end, preorder, pIndex, d)
    print(value, end='')

    return pIndex


def findPostorder(inorder, preorder):

    d = {}

    for i, e in enumerate(inorder):
        d[e] = i

    pIndex = 0

    printPostorder(0, len(inorder) - 1, preorder, pIndex, d)


if __name__ == '__main__':

    inorder = list(input())
    preorder = list(input())

    findPostorder(inorder, preorder)
