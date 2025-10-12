# 45+ Clock & Time Coding Problems (Priority-ordered)

A prioritized list of **45+ coding problems** about **time, clocks, intervals, and scheduling** — ordered so you can study **High**-priority problems first (common in OAs and interviews).

> **Order:** High priority → Medium priority → Low priority

---

## High Priority (study these first)

| # | Problem | Short description | Difficulty | Link |
|---:|---|---|---:|---|
| 1 | Minimum Time Difference | Given a list of times ("HH:MM"), find the minimum minutes difference between any two time points (wrap-around allowed). | Medium | https://leetcode.com/problems/minimum-time-difference/ |
| 2 | Maximum Time Difference (pick two times with max gap) | Given times (with AM/PM), find the pair with the maximum gap (consider circular day). | Medium | https://www.geeksforgeeks.org/difference-between-two-times/ |
| 3 | Next Closest Time | Given a time, build the next closest time using only the digits present in the original time. | Medium | https://leetcode.com/problems/next-closest-time/ |
| 4 | Angle Between Hands of a Clock | Given hour and minutes, compute the smaller angle between hour and minute hands. | Easy | https://leetcode.com/problems/angle-between-hands-of-a-clock/ |
| 5 | Time-based Key-Value Store | Implement a key-value store that can return values at a given timestamp. | Medium | https://leetcode.com/problems/time-based-key-value-store/ |
| 6 | Merge Time Intervals | Merge overlapping intervals (useful for schedules). | Medium | https://leetcode.com/problems/merge-intervals/ |
| 7 | Meeting Rooms II (Min rooms) | Minimum number of conference rooms required to host all meetings. | Medium | https://leetcode.com/problems/meeting-rooms-ii/ |
| 8 | My Calendar I / II / III (Design calendar) | Design a calendar that can book events (and handle overlaps / counts). | Medium → Hard | https://leetcode.com/problems/my-calendar-i/ |
| 9 | Number of Recent Calls / Hit Counter | Implement a data structure returning number of hits in past k seconds. | Easy | https://leetcode.com/problems/number-of-recent-calls/ |
|10 | Sliding-window on timestamps (max events in k minutes) | Given timestamps, find max events in any k-minute window (two-pointer). | Medium | https://www.geeksforgeeks.org/sliding-window-techniques-set-1/ |
|11 | Time Conversion (12-hour ↔ 24-hour) | Convert `hh:mm:ssAM/PM` to 24-hour format (and vice-versa). | Easy | https://www.hackerrank.com/challenges/time-conversion/problem |
|12 | Event Scheduling — Maximum Non-Overlapping (Activity Selection) | Given events, choose maximum number that can be attended (greedy by finish time). | Easy/Medium | https://www.geeksforgeeks.org/activity-selection-problem/ |
|13 | Meeting Rooms (Can attend all?) | Given meeting intervals, check if a person can attend all of them (no overlaps). | Easy | https://leetcode.com/problems/meeting-rooms/ |
|14 | Minimum Number of Platforms / Overlap counts | Given arrival & departure times, find min platforms needed (sweep-line). | Medium | https://www.geeksforgeeks.org/minimum-number-platforms-required-for-a-railway-station/ |
|15 | Maximum Overlap of Intervals | Find the maximum number of overlapping intervals at any point in time. | Medium | https://www.geeksforgeeks.org/maximum-number-overlapping-intervals/ |
|16 | Sort Times in 12-hour Format | Sort a list of time strings with AM/PM correctly. | Easy | https://stackoverflow.com/questions/18019844/sort-by-12-hour-time |
|17 | Find largest free gap from busy schedule | Given booked intervals, find the largest free interval in a day. | Medium | https://leetcode.com/problems/employee-free-time/ |
|18 | Rate Limiter / Token Bucket / Leaky Bucket (time-based) | Implement rate limiting algorithms that refill tokens over time. | Hard | https://en.wikipedia.org/wiki/Token_bucket |
|19 | Log processing: peak requests per minute | Given request timestamps, compute peak throughput in any sliding minute (or k-minute window). | Medium | https://www.geeksforgeeks.org/sliding-window-techniques-set-1/ |
|20 | Date arithmetic with calendar rules (leap years) | Correctly compute days between dates accounting leap years. | Easy/Medium | https://www.geeksforgeeks.org/find-number-of-days-between-two-dates/ |
|21 | Timezone-aware scheduling conflict detection | Detect conflicts when events stored in different timezones. | Hard | https://www.iana.org/time-zones |
|22 | Design a Calendar Service (mini Google Calendar) | Design API and data model for booking events, availability, recurring events. | System Design | https://github.com/donnemartin/system-design-primer#calendar-service-design-notes |
|23 | Timezone daylight-saving tricky cases (DST transitions) | Handle ambiguous or missing local times during DST transitions. | Hard | https://en.wikipedia.org/wiki/Tz_database |

---

## Medium Priority (use next)

| # | Problem | Short description | Difficulty | Link |
|---:|---|---|---:|---|
|24 | Largest Time for Given Digits | Given 4 digits, arrange to form the largest valid 24-hour time "HH:MM". | Medium | https://leetcode.com/problems/largest-time-for-given-digits/ |
|25 | Add Minutes to Time / Time Arithmetic | Add/subtract minutes to a given time string handling wrap-around and AM/PM. | Easy | https://www.geeksforgeeks.org/add-minutes-to-time/ |
|26 | Timezone conversion / offset math | Convert between time zones (consider offsets, DST caveats). | Medium | https://www.timeanddate.com/time/zones/ |
|27 | Parse ISO-8601 / RFC3339 Timestamps | Parse and validate standard timestamp formats (timezone-aware). | Medium | https://datatracker.ietf.org/doc/html/rfc3339 |
|28 | Employee Free Time (common free intervals) | Given schedules of employees, return common free time intervals. | Hard | https://leetcode.com/problems/employee-free-time/ |
|29 | Digital Clock Segment Changes | Count the number of 7-seg display changes between two times or total changes in 24 hours. | Medium | https://learn.sparkfun.com/tutorials/7-segment-displays/all |
|30 | Validate Time String (HH:MM(:SS) and AM/PM) | Use regex / parsing to check if a time string is valid. | Easy | https://www.geeksforgeeks.org/validate-time-format-hhmmss-using-regex/ |
|31 | Circular (clock) distance between times | On a circular 12-hour clock, find shortest/longest separation between points. | Medium | https://leetcode.com/problems/minimum-time-difference/ (related) |
|32 | Time Slot Selection to Maximize Minimum Gap (choose k times) | Choose k times/intervals to maximize minimum gap — use binary search + greedy (similar to aggressive cows). | Hard | https://www.spoj.com/problems/AGGRCOW/ |
|33 | Rolling / Sliding Average by time window (time series) | Compute moving average over timestamps (irregular intervals). | Medium | https://pandas.pydata.org/docs/reference/api/pandas.DataFrame.rolling.html |
|34 | Cron expression parsing & next-run calculation | Parse cron-like expressions and compute next trigger time. | Hard | https://en.wikipedia.org/wiki/Cron |
|35 | Timestamp compression / delta encoding | Store sorted timestamps efficiently (delta encoding, variable-length). | Medium | https://en.wikipedia.org/wiki/Delta_encoding |
|36 | Find k closest timestamps to target | Given sorted timestamps, return k closest to a target time. | Medium | https://leetcode.com/problems/find-k-closest-elements/ |
|37 | Time formatting & rounding problems | Round times to nearest 5/15/30 minutes and format output. | Easy | https://stackoverflow.com/questions/3463930/how-to-round-the-time-to-the-nearest-15-minutes-in-java |
|38 | Recurring events handling (weekly/monthly rules) | Expand recurring rules into explicit event instances within a range (iCal RFC). | Hard | https://datatracker.ietf.org/doc/html/rfc5545 |
|39 | Business day calculations (next business day) | Add N business days to a date (skip weekends/holidays). | Medium | https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.tseries.offsets.BusinessDay.html |
|40 | Timestamp normalization (various formats to epoch) | Normalize inputs like "YYYY/MM/DD HH:MM" or epoch ms to a single format. | Easy | https://en.wikipedia.org/wiki/Unix_time |
|41 | Time-window deduplication (events within k seconds considered same) | Deduplicate events that occur within a small time window. | Medium | https://www.confluent.io/blog/stream-processing-with-apache-kafka/ |
|42 | Cron / rate-limited scheduling integration | Integrate cron-like scheduling with rate limits (applied system patterns). | Medium | https://en.wikipedia.org/wiki/Token_bucket |

---

## Low Priority (optional / puzzles / niche)

| # | Problem | Short description | Difficulty | Link |
|---:|---|---|---:|---|
|43 | Palindromic Times (24-hour) | Enumerate/count times that read the same forwards and backwards (e.g. 13:31). | Easy | https://stackoverflow.com/questions/35197777/write-a-program-to-output-all-palindromic-times-displayed-by-a-24-hour-digital-c |
|44 | When Do Clock Hands Overlap? (math) | How many times in a day do hour and minute hands coincide? (theory/riddle). | Brain-teaser | https://math.stackexchange.com/questions/2472/how-many-times-do-the-minute-and-hour-hand-overlap-in-a-day |
|45 | Times When Hands are at Right Angle | Determine/count times the hands form a 90° angle (and compute times precisely). | Brain-teaser | https://math.stackexchange.com/questions/606794/how-many-times-are-the-hands-of-a-clock-at-90-degrees |
|46 | Timestamp compression / storage patterns (deep dive) | Advanced systems topic: efficient timestamp storage for telemetry. | Medium | https://loki.storage/ (example project) |
|47 | Leap second handling (edge cases) | Consider rare leap-second adjustments in time arithmetic (mostly theoretical). | Hard | https://en.wikipedia.org/wiki/Leap_second |

---
