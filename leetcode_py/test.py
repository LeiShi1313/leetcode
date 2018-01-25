day_start=1
day_end=12

class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
    def __repr__(self):
        return '[' + str(self.start) + ',' + str(self.end) + ']'

def findFreeIntervals(busyIntervals):
    free_intervals = [Interval(day_start, day_end)]
    for i in busyIntervals:
        to_remove = []
        for idx, free_i in enumerate(free_intervals):
            # free_i_start i_start free_i_end i_end
            if free_i.start < i.start and i.start < free_i.end <= i.end:
                free_i.end = i.start
            # i_start free_i_start free_i_end i_end
            elif i.start <= free_i.start and free_i.end <= i.end:
                to_remove.append(free_i)
            # i_start free_i_start i_end free_i_end
            elif i.start <= free_i.start and free_i.start < i.end < free_i.end:
                free_i.start = i.end
            # free_i_start i_start i_end free_i_end
            elif free_i.start <= i.start and free_i.end >= i.end:
                new_end = free_i.end
                free_i.end = i.start
                free_intervals = free_intervals[0:idx+1] + [Interval(i.end, new_end)] + free_intervals[idx+1:]
        for free_i in to_remove:
            free_intervals.remove(free_i)
    return free_intervals

intervals = [Interval(2, 5), Interval(3,4), Interval(5,6), Interval(9, 10), Interval(11,12), Interval(5,10), Interval(1,11)]
print findFreeIntervals(intervals)