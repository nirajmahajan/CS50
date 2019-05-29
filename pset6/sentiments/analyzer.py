import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        
        # define sets
        self.negative = set()
        self.positive = set()
        
        # open the files
        file_n = open(negatives, "r")
        file_p = open(positives, "r")
        
        # iterate over both files
        # if first character is ";" then its a comment
        # hence we omit that word
        for line in file_p:
            if line.startswith(";") == False:
                self.positive.add(line.rstrip("\n"))

        for line in file_n:
            if line.startswith(";") == False:
                self.negative.add(line.rstrip("\n"))
                
        file_n.close()
        file_p.close()

    def analyze(self, text):

        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        score = 0
        
        for word in tokens:
            if word.lower() in self.negative:
                score -= 1
            elif word.lower() in self.positive:
                score += 1
            else:
                continue
                
        return score
