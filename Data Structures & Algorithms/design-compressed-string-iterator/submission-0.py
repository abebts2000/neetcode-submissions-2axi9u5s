class StringIterator:

    def __init__(self, compressedString: str):
        self.compressed = compressedString
        self.uncompressed = self.uncompress(compressedString)
        self.indx = 0

    def uncompress(self, input):
        i = 0
        output = ""
        while i < len(input):
            char = input[i]
            i += 1
            num_str = ""
            while i < len(input) and input[i].isdigit():
                num_str += input[i]
                i += 1
            output += char * int(num_str)
        return output

    def next(self) -> str:
        if not self.hasNext():
            return " "
        ch = self.uncompressed[self.indx]
        self.indx += 1
        return ch

    def hasNext(self) -> bool:
        return self.indx < len(self.uncompressed)