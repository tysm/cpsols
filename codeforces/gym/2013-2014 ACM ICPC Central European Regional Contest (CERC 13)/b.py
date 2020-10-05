t = int(input())

for _ in range(t):
    sounds = input().split()

    s = input()
    while s != "what does the fox say?":
        s = s.split()
        for i in range(1, len(s)):
            for j in range(len(sounds)):
                if sounds[j] == s[i]:
                    sounds[j] = "_"
        s = input()
    print(" ".join(res for res in sounds if res != "_"))
