
class Book:
    def __init__(self, title, author, price):
        self.title = title
        self.author = author
        self.price = price

    def display_info(self):
        print(f"Title : {self.title}")
        print(f"Author: {self.author}")
        print(f"Price : ₹{self.price:.2f}")


class EBook(Book):
    def __init__(self, title, author, price, file_size):
        
        super().__init__(title, author, price)
        self.file_size = file_size  

    def display_info(self):
        print("📘 EBook Details:")
        
        super().display_info()
        print(f"File Size: {self.file_size} MB")



if __name__ == "__main__":
    print("=== Physical Book ===")
    b1 = Book("The Alchemist", "Paulo Coelho", 350)
    b1.display_info()

    print("\n=== EBook ===")
    e1 = EBook("The Alchemist", "Paulo Coelho", 250, 5)
    e1.display_info()
