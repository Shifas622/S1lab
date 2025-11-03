class Time:
    def __init__(self):
        self.__hour = 0
        self.__minute = 0
        self.__second =0
    def set__time(self,hour,minute=0,second=0):
        self.__hour=hour
        self.__minute=minute
        self.__second=second
    def display__time(self):
        print(self.__hour,":",self.__minute,":",self.__second)
t=Time()


