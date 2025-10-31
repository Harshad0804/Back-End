def book_repair():
    name = input("Enter customer name: ")
    device = input("Enter device type: ")
    issue = input("Enter issue: ")
    due = input("Enter due date: ")
    return {"name": name, "device": device, "issue": issue, "due": due, "status": "Pending"}

def generate_bill(order):
    try:
        parts = float(input("Enter parts cost: "))
        repair = float(input("Enter repair fee: "))
        tax = 0.18 * (parts + repair)
        total = parts + repair + tax
        disc = input("Apply discount? (y/n): ").lower()
        if disc == 'y':
            d = float(input("Discount %: "))
            total -= total * d / 100
        print("\n------ BILL ------")
        print(f"Customer: {order['name']}\nDevice: {order['device']}\nIssue: {order['issue']}")
        print(f"Parts: ₹{parts}\nRepair: ₹{repair}\nTax: ₹{tax:.2f}\nTotal: ₹{total:.2f}")
        order["status"] = "Completed"
    except ValueError:
        print("Invalid input! Enter numbers only.")

def main():
    repairs = []
    while True:
        print("\n1. New Repair  2. Generate Bill  3. Show All  4. Exit")
        ch = input("Enter choice: ")
        if ch == '1':
            repairs.append(book_repair())
        elif ch == '2':
            for i, r in enumerate(repairs):
                print(i+1, r["name"], "-", r["status"])
            try:
                idx = int(input("Select order no: ")) - 1
                generate_bill(repairs[idx])
            except:
                print("Invalid selection!")
        elif ch == '3':
            for r in repairs: print(r)
        elif ch == '4':
            break
        else:
            print("Invalid choice!")

main()
