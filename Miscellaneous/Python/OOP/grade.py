from pipe import where


x = range(0, 101, 1)
grade_policy = {
    "A" : list(x
        | where(lambda a: a >= 86 and a <= 100)
    ),
    "B+" : list(x
        | where(lambda a: a >= 82 and a <= 85)
    ),
    "B" : list(x
        | where(lambda a: a >= 78 and a <= 81)
    ),
    "C+" : list(x
        | where(lambda a: a >= 70 and a <= 77)
    ),
    "C" : list(x
        | where(lambda a: a >= 62 and a <= 69)
    ),
    "D+" : list(x
        | where(lambda a: a >= 54 and a <= 61)
    ),
    "D" : list(x
        | where(lambda a: a >= 50 and a <= 53)
    ),
    "F" : list(x
        | where(lambda a: a < 50)
    )
}

class Grade:
    def __init__(self, obtained_marks, total_marks):
        self.obtained_marks = obtained_marks
        self.total_marks = total_marks
    
    @property
    def precentage(self):
        return (self.obtained_marks / self.total_marks) * 100

    
    @staticmethod
    def get_grade(percentage, **kwargs):
        G = str()
        for grade, p in kwargs.items():
            if percentage in p:
                G = grade
        return G

grade = Grade(76, 100)
percent = grade.precentage
print("Percentage: {a:.2f}%".format(a = grade.precentage))
print("Grade: {a:}".format(a = Grade.get_grade(percent, **grade_policy)))
