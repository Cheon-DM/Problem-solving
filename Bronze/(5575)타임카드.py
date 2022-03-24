a_workhour, a_workmin, a_worksec, a_homehour, a_homemin, a_homesec = map(int, input().split())
b_workhour, b_workmin, b_worksec, b_homehour, b_homemin, b_homesec = map(int, input().split())
c_workhour, c_workmin, c_worksec, c_homehour, c_homemin, c_homesec = map(int, input().split())

def workingTime(Wh, Wm, Ws, Hh, Hm, Hs):
    if Hs < Ws :
        if Hm == 0 :
            Hh -= 1
            Hm = 59
            Hs += 60
            s = Hs - Ws
        else:
            Hm -= 1
            Hs += 60
            s = Hs - Ws
    else :
        s = Hs - Ws
    if Hm < Wm :
        Hh -= 1
        Hm += 60
        m = Hm - Wm
    else :
        m = Hm - Wm
    h = Hh - Wh
    print(h, m, s)

workingTime(a_workhour, a_workmin, a_worksec, a_homehour, a_homemin, a_homesec)
workingTime(b_workhour, b_workmin, b_worksec, b_homehour, b_homemin, b_homesec)
workingTime(c_workhour, c_workmin, c_worksec, c_homehour, c_homemin, c_homesec)