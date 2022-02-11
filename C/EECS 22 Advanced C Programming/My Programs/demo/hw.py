# This program was taken from ~eecs22/bin/hw.py because I was curious to see a
# relevant python program.

#!/usr/bin/env python
#This program determines the current homework folder name
#
# 01/03/22 RD   updated for EECS22 W22
# 07/01/18 MC   updated for EECS22 Fall 2018 to match submit.py and listfiles.py
# 01/11/18 MC   updated for EECS22L Winter 2018
# 09/14/17 TS	updated for EECS22 Fall 2017
# 01/05/17 HC	updated for EECS22L Winter 2017
# 09/20/16 GL	updated for EECS22 Fall 2016
# 09/26/12 WC   updated for EECS22 Fall 2012
# 09/19/11 WC	updated for EECS22 Fall 2011
# 09/21/10 WC	updated for EECS10 Fall 2010
# 11/29/07 GS   extend HW7 deadline by 3 days to 12/06/07 noon
# 09/27/07 GS	updated for EECS10 Fall 2007
# 01/10/07 MP	updated for EECS10 Winter 2007
# 11/22/06 RD	deadline for HW7 extended for 48 hours
# 09/25/06 GS   adjust deadline from midnight to noon
# 09/16/06 GS   adjust for EECS10 in F06
# 09/16/05 LZ   adjust for EECS10 in F05
# 01/24/05 RD	adjusted for EECS 211 in W05

## This program is just a modification of the listfiles.py

EECS22 = "EECS 22"
EECS22L = "EECS 22L"
CURR_COURSE = "EECS 22" # "EECS22L"
CURR_QUARTER = "Winter 2022"
HOMEWORK_REPO = "/users/grad2/doemer/eecs22/rep/"   # homework repository directory
YEAR = 2022
EECS22L_PROJECTS = ["chess", "chessV2"]

hw  = "hw1"
due = 0
past_due_allowed = 0 * 60 * 60 #seconds in one day

# due dates for each assignemnt in python time format
# (<year>, <month>, <day>, <hour (24h)>, <minute>, <second> ...) : "<hw name>"

if CURR_COURSE == EECS22L:
    due_dates = {
         # five submissions of eecs22L for project 1
        (YEAR, 4, 14, 9, 0, 0, 0, 0, -1) : "hw1",
        (YEAR, 4, 20, 0, 0, 0, 0, 0, -1) : "hw2",
        (YEAR, 4, 27, 0, 0, 0, 0, 0, -1) : "hw3",
        (YEAR, 5, 4, 0, 0, 0, 0, 0, -1) : "hw4",
        (YEAR, 5, 12, 9, 1, 0, 0, 0, -1) : "hw5",
        ## four submission deadlines of EECS22L for project 2
        (YEAR, 5, 18, 0, 0, 0, 0, 0, -1) : "hw6",
        (YEAR, 5, 25, 0, 0, 0, 0, 0, -1) : "hw7",
        (YEAR, 6, 1, 0, 0, 0, 0, 0, -1) : "hw8",
        (YEAR, 6, 12, 0, 0, 0, 0, 0, -1) : "hw9",
    }
else:
    due_dates = {
      # five projects of eecs22
      (YEAR, 1, 12, 12, 0, 0, 0, 0, -1) : "hw1",
      (YEAR, 1, 26, 12, 0, 0, 0, 0, -1) : "hw2",
      (YEAR, 2,  9, 12, 0, 0, 0, 0, -1) : "hw3",
      (YEAR, 2, 23, 12, 0, 0, 0, 0, -1) : "hw4",
      (YEAR, 3,  9, 12, 0, 0, 0, 0, -1) : "hw5",
    }

import sys
import os
import re
import os.path
import time
import string

# get current time, find the earliest deadline {di} such that curr_time < {di}
def setParameters():
    if len(sys.argv) > 1:
        print("No arguments allowed for current script.")
        sys.exit(1)
    global hw, due
    due_times = map(time.mktime, due_dates.keys())
    due_times.sort()
    curr_time = time.time()
    for i in due_times:
        if curr_time > i + past_due_allowed:
            continue
        due = i
        break
    if due == 0:
        # all deadlines are passed, nothing can be submitted
        sys.exit(1)
    for i in due_dates.keys():
        if time.mktime(i) == due:
            hw = due_dates[i]
            due = i
            break

setParameters()
import datetime
# EECS22L: the last deadline of project 1, if current time passes it, then hw = "taxi"
project1_deadline = datetime.datetime(YEAR, 5, 13, 0, 0, 0, 0)
if CURR_COURSE == EECS22L:
    curr_time = datetime.datetime.now()
    #print(curr_time)
    #print(project1_deadline)
    if curr_time < project1_deadline:
        hw = EECS22L_PROJECTS[0] #project1
    else:
        #print("The deadline of project 1 has passed.")
        hw = EECS22L_PROJECTS[1] #project2
print hw
