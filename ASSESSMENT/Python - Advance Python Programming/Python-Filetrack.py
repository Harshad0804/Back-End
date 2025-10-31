"""
FixTrack - Console Repair Order & Billing System
Assessment solution implementing:
 - Repair order booking (customer name, device type, issue, due date)
 - In-memory storage of orders
 - Mark orders complete and generate invoice (parts list, repair fee, tax, discount)
 - Basic input validation and clean function-based structure
 - Formatted printed invoice

Run: python fixtrack.py
"""

import datetime
import itertools
import textwrap

# Global in-memory storage
_orders = {}
_order_id_counter = itertools.count(1001)  # start IDs from 1001


# ---------- Utilities ----------
def input_nonempty(prompt):
    while True:
        s = input(prompt).strip()
        if s:
            return s
        print("Input cannot be empty. Please try again.")


def input_date(prompt):
    # Accepts YYYY-MM-DD
    while True:
        s = input(prompt).strip()
        try:
            dt = datetime.datetime.strptime(s, "%Y-%m-%d").date()
            return dt
        except ValueError:
            print("Please enter date in YYYY-MM-DD format (e.g. 2025-10-31).")


def input_positive_float(prompt, allow_zero=False):
    while True:
        s = input(prompt).strip()
        try:
            v = float(s)
            if allow_zero and v >= 0:
                return v
            if v > 0:
                return v
            raise ValueError
        except ValueError:
            print("Please enter a positive number.")


def input_yes_no(prompt):
    while True:
        s = input(prompt + " (y/n): ").strip().lower()
        if s in ("y", "yes"):
            return True
        if s in ("n", "no"):
            return False
        print("Enter y or n.")


def money(v):
    return f"₹{v:,.2f}"


# ---------- Core features ----------
def create_repair_order():
    print("\n--- Create New Repair Order ---")
    customer = input_nonempty("Customer name: ")
    device_type = input_nonempty("Device type (e.g. mobile, laptop): ")
    issue = input_nonempty("Issue description: ")
    due_date = input_date("Due date (YYYY-MM-DD): ")
    order_id = next(_order_id_counter)
    order = {
        "id": order_id,
        "customer": customer,
        "device_type": device_type,
        "issue": issue,
        "created_on": datetime.date.today(),
        "due_date": due_date,
        "status": "OPEN",  # OPEN or COMPLETE
        "parts": [],  # each part: dict(name, qty, unit_price)
        "repair_fee": 0.0,
        "tax_percent": 18.0,  # default tax %
        "discount": 0.0,  # absolute discount amount (can be 0)
    }
    _orders[order_id] = order
    print(f"Order created with ID: {order_id}")
    return order_id


def list_orders(show_all=True):
    print("\n--- Repair Orders ---")
    if not _orders:
        print("No orders found.")
        return
    rows = []
    for oid, ordn in sorted(_orders.items()):
        if not show_all and ordn["status"] != "OPEN":
            continue
        rows.append((oid, ordn["customer"], ordn["device_type"], ordn["due_date"], ordn["status"]))
    print(f"{'ID':6} {'Customer':20} {'Device':10} {'Due Date':12} {'Status':8}")
    print("-" * 62)
    for r in rows:
        print(f"{r[0]:<6} {r[1]:20.20} {r[2]:10.10} {r[3].isoformat():12} {r[4]:8}")
    print()


def view_order_detail():
    print("\n--- View Order Detail ---")
    try:
        oid = int(input_nonempty("Enter order ID: "))
    except ValueError:
        print("Invalid ID.")
        return
    ordn = _orders.get(oid)
    if not ordn:
        print("Order not found.")
        return
    print_order(ordn)


def print_order(ordn):
    print("\n" + "=" * 60)
    print(f"Order ID: {ordn['id']}\tStatus: {ordn['status']}")
    print(f"Customer: {ordn['customer']}")
    print(f"Device: {ordn['device_type']}")
    print(f"Issue: {ordn['issue']}")
    print(f"Created on: {ordn['created_on'].isoformat()}   Due date: {ordn['due_date'].isoformat()}")
    print("-" * 60)
    print("Parts:")
    if ordn["parts"]:
        print(f"{'Name':20} {'Qty':>5} {'Unit':>12} {'Total':>12}")
        for p in ordn["parts"]:
            total = p["qty"] * p["unit_price"]
            print(f"{p['name']:20.20} {p['qty']:5d} {money(p['unit_price']):>12} {money(total):>12}")
    else:
        print("  (No parts recorded)")
    print("-" * 60)
    print(f"Repair fee: {money(ordn['repair_fee'])}")
    print(f"Tax %: {ordn.get('tax_percent', 0.0)}  Discount: {money(ordn.get('discount', 0.0))}")
    print("=" * 60 + "\n")


def edit_order_parts_and_fees(ordn):
    print("\n--- Edit Parts & Fees for Order", ordn["id"], "---")
    while True:
        print("\n1) Add part\n2) Remove part\n3) Set repair fee\n4) Set tax percent\n5) Set discount amount\n6) Back")
        choice = input_nonempty("Choose option: ")
        if choice == "1":
            name = input_nonempty("Part name: ")
            qty = int(input_positive_float("Quantity (integer): ", allow_zero=False))
            unit_price = input_positive_float("Unit price: ")
            ordn["parts"].append({"name": name, "qty": int(qty), "unit_price": unit_price})
            print("Part added.")
        elif choice == "2":
            if not ordn["parts"]:
                print("No parts to remove.")
                continue
            for i, p in enumerate(ordn["parts"], 1):
                print(f"{i}) {p['name']} x{p['qty']} @ {money(p['unit_price'])}")
            idx = int(input_nonempty("Enter part number to remove: "))
            if 1 <= idx <= len(ordn["parts"]):
                removed = ordn["parts"].pop(idx - 1)
                print(f"Removed part {removed['name']}.")
            else:
                print("Invalid number.")
        elif choice == "3":
            fee = input_positive_float("Enter repair fee (flat): ", allow_zero=True)
            ordn["repair_fee"] = fee
            print("Repair fee set.")
        elif choice == "4":
            tp = input_positive_float("Enter tax percent (e.g. 18 for 18%): ", allow_zero=True)
            ordn["tax_percent"] = tp
            print("Tax percent set.")
        elif choice == "5":
            disc = input_positive_float("Enter discount amount (absolute, ₹): ", allow_zero=True)
            ordn["discount"] = disc
            print("Discount set.")
        elif choice == "6":
            break
        else:
            print("Choose a valid option.")


def finalize_and_generate_invoice():
    print("\n--- Complete Repair & Generate Invoice ---")
    try:
        oid = int(input_nonempty("Enter order ID to complete: "))
    except ValueError:
        print("Invalid ID.")
        return
    ordn = _orders.get(oid)
    if not ordn:
        print("Order not found.")
        return
    if ordn["status"] == "COMPLETE":
        print("Order already completed. Showing invoice preview.")
        invoice = build_invoice(ordn)
        print_invoice(invoice)
        return

    # Let user edit parts/fees before finalizing
    print_order(ordn)
    if input_yes_no("Would you like to edit parts/fees before finalizing?"):
        edit_order_parts_and_fees(ordn)

    # Confirm completion
    if not input_yes_no("Mark this order as COMPLETE and generate invoice?"):
        print("Operation cancelled.")
        return

    ordn["status"] = "COMPLETE"
    ordn["completed_on"] = datetime.date.today()

    invoice = build_invoice(ordn)
    print_invoice(invoice)

    # Optionally keep a simple "receipt" note in order for future extension; currently in-memory only.
    ordn["last_invoice"] = invoice


def build_invoice(ordn):
    # Compute parts total
    parts_total = sum(p["qty"] * p["unit_price"] for p in ordn["parts"])
    repair_fee = ordn.get("repair_fee", 0.0)
    subtotal = parts_total + repair_fee
    tax_percent = ordn.get("tax_percent", 0.0)
    tax_amount = subtotal * (tax_percent / 100.0)
    discount = ordn.get("discount", 0.0)
    total_due = subtotal + tax_amount - discount
    if total_due < 0:
        total_due = 0.0

    invoice = {
        "order_id": ordn["id"],
        "customer": ordn["customer"],
        "device": ordn["device_type"],
        "issue": ordn["issue"],
        "created_on": ordn["created_on"],
        "completed_on": ordn.get("completed_on", datetime.date.today()),
        "parts": ordn["parts"],
        "parts_total": parts_total,
        "repair_fee": repair_fee,
        "subtotal": subtotal,
        "tax_percent": tax_percent,
        "tax_amount": tax_amount,
        "discount": discount,
        "total_due": total_due,
    }
    return invoice


def print_invoice(inv):
    # Nicely formatted invoice printout
    print("\n" + "=" * 70)
    print(" " * 18 + "FixTrack - Repair Invoice".upper())
    print("=" * 70)
    print(f"Invoice for Order ID: {inv['order_id']}    Date: {inv['completed_on'].isoformat()}")
    print(f"Customer: {inv['customer']}")
    print(f"Device: {inv['device']}")
    print(f"Issue: {inv['issue']}")
    print("-" * 70)
    if inv["parts"]:
        print(f"{'Part':25} {'Qty':>5} {'Unit Price':>12} {'Line Total':>12}")
        for p in inv["parts"]:
            line = p["qty"] * p["unit_price"]
            print(f"{p['name'][:25]:25} {p['qty']:5d} {money(p['unit_price']):>12} {money(line):>12}")
    else:
        print("(No parts)")
    print("-" * 70)
    print(f"{'Parts total:':>54} {money(inv['parts_total']):>14}")
    print(f"{'Repair fee:':>54} {money(inv['repair_fee']):>14}")
    print(f"{'Subtotal:':>54} {money(inv['subtotal']):>14}")
    print(f"{'Tax (' + str(inv['tax_percent']) + '%):':>54} {money(inv['tax_amount']):>14}")
    print(f"{'Discount:':>54} -{money(inv['discount']):>13}")
    print("-" * 70)
    print(f"{'TOTAL DUE:':>54} {money(inv['total_due']):>14}")
    print("=" * 70 + "\n")


# ---------- Main menu ----------
def main_menu():
    print(textwrap.dedent("""
    Welcome to FixTrack - Simple Repair Order & Billing Console
    ----------------------------------------------------------
    """))
    while True:
        print("Main menu:")
        print("1) Create new repair order")
        print("2) List all orders")
        print("3) List open orders")
        print("4) View order detail")
        print("5) Edit parts/fees for an order")
        print("6) Complete repair & generate invoice")
        print("7) Exit")
        choice = input_nonempty("Choose an option (1-7): ")
        if choice == "1":
            create_repair_order()
        elif choice == "2":
            list_orders(show_all=True)
        elif choice == "3":
            list_orders(show_all=False)
        elif choice == "4":
            view_order_detail()
        elif choice == "5":
            try:
                oid = int(input_nonempty("Enter order ID to edit: "))
            except ValueError:
                print("Invalid ID.")
                continue
            ordn = _orders.get(oid)
            if not ordn:
                print("Order not found.")
                continue
            edit_order_parts_and_fees(ordn)
        elif choice == "6":
            finalize_and_generate_invoice()
        elif choice == "7":
            print("Exiting FixTrack. Goodbye!")
            break
        else:
            print("Invalid choice — please pick 1-7.")


if __name__ == "__main__":
    # Insert a small demo order to help testers see functionality quickly (optional).
    sample_id = next(_order_id_counter)
    _orders[sample_id] = {
        "id": sample_id,
        "customer": "Ravi Kumar",
        "device_type": "Mobile Phone",
        "issue": "Broken screen; not charging",
        "created_on": datetime.date.today(),
        "due_date": datetime.date.today() + datetime.timedelta(days=3),
        "status": "OPEN",
        "parts": [],
        "repair_fee": 0.0,
        "tax_percent": 18.0,
        "discount": 0.0,
    }
    main_menu()
