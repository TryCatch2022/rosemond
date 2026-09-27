class Bounds:
    """The address set of one function.

    Stands in for the old ``(start, end)`` tuple that codegen used to decide
    whether a jump stays inside the function: indexing still yields the
    enclosing interval, so old call sites keep working, but ``in`` tests real
    membership, which is what a function built from several disjoint ranges
    needs.
    """

    def __init__(self, ranges):
        self.ranges = sorted(ranges)
        self.start = self.ranges[0][0]
        self.end = self.ranges[-1][1]

    def __getitem__(self, index):
        return (self.start, self.end)[index]

    def __contains__(self, address):
        for start, end in self.ranges:
            if start <= address < end:
                return True
        return False

    def __repr__(self):
        return 'Bounds(%s)' % ', '.join('0x%08x-0x%08x' % r for r in self.ranges)
