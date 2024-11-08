#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declare variables for customer details
    string customer_code, name, address;
    char customer_category;
    int previous_meter_reading, units_consumed;
    
    // Variables for calculating charges
    float basic_consumption = 0, fuel_surcharge = 0, total_consumption_charge = 0;
    float discount = 0, net_consumption = 0, vat, amount_payable;

    // Input Customer Details
    cout << "Enter customer code= ";
    cin >> customer_code;
    cout << "Enter previous_meter_reading= ";
    cin >> previous_meter_reading;
    cout << "Enter units_consumed= ";
    cin >> units_consumed;
    cout << "Enter name= ";
    cin >> name;
    cout << "Enter address= ";
    cin >> address;
    cout << "Enter customer_category: (D for Domestic, I for Industrial)= ";
    cin >> customer_category;

    // Fuel Surcharge Calculation (65 fils per kWh)
    fuel_surcharge = units_consumed * 0.065;

    // Basic Consumption Calculation based on Category and Slab Rate
    if (customer_category == 'D') {  // Domestic category
        // Apply slab rates for domestic customers
        if (units_consumed <= 2000)
            basic_consumption = units_consumed * 23;
        else if (units_consumed <= 4000)
            basic_consumption = (2000 * 23) + (units_consumed - 2000) * 28;
        else if (units_consumed <= 6000)
            basic_consumption = (2000 * 23) + (2000 * 28) + (units_consumed - 4000) * 32;
        else
            basic_consumption = (2000 * 23) + (2000 * 28) + (2000 * 32) + (units_consumed - 6000) * 38;
    } else if (customer_category == 'I') {  // Industrial category
        // Apply slab rates for industrial customers
        if (units_consumed <= 10000)
            basic_consumption = units_consumed * 23;
        else
            basic_consumption = (10000 * 23) + (units_consumed - 10000) * 38;
    } else {
        // Invalid customer category entered
        cout << "Invalid customer category" << endl;
        return 0; // Exit the program if category is invalid
    }

    // Total Consumption Charge Calculation (basic consumption + fuel surcharge)
    total_consumption_charge = basic_consumption + fuel_surcharge;

    // Discount Calculation for Domestic Customers with <= 500 kWh
    if (customer_category == 'D' && units_consumed <= 500) {
        discount = total_consumption_charge * 0.10;  // 10% discount
    }

    // Net Consumption Charge after applying any discount
    net_consumption = total_consumption_charge - discount;

    // Meter Surcharge (AED 6 flat rate)
    int meter_surcharge = 6;

    // Total Bill Calculation (Excluding VAT)
    float total_bill = net_consumption + meter_surcharge;

    // VAT Calculation (5% of total bill)
    vat = total_bill * 0.05;

    // Amount Payable (Including VAT)
    amount_payable = total_bill + vat;

    // Display Formatted Bill
    cout << "\n-----------------------------------------------------------\n";
    cout << "\t\t   Dubai Electricity\n";
    cout << "\t   Electricity Consumption Bill\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Customer Code   : " << customer_code << "\n";
    cout << "Name            : " << name << "\n";
    cout << "Address         : " << address << "\n";
    cout << "Customer Category : " << (customer_category == 'D' ? "Domestic" : "Industrial") << "\n";
    cout << "Previous meter reading date : 5/5/2021\n";
    cout << "Current meter reading date  : 6/6/2021\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Previous Reading\tCurrent Reading\tUnits Consumed\tUnit Price (fils)\n";
    cout << previous_meter_reading << "\t\t" << units_consumed << "\t\t" << units_consumed << "\t\tAED " << fuel_surcharge << "\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Fuel surcharge           : AED " << fuel_surcharge << "\n";
    cout << "Total consumption charges: AED " << total_consumption_charge << "\n";
    cout << "Discount                 : AED " << discount << "\n";
    cout << "Net Consumption Charges  : AED " << net_consumption << "\n";
    cout << "Meter surcharge          : AED " << meter_surcharge << "\n";
    cout << "Total Bill Amount        : AED " << total_bill << "\n";
    cout << "VAT 5%                   : AED " << vat << "\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Total (including VAT)    : AED " << amount_payable << "\n";
    cout << "-----------------------------------------------------------\n";

    return 0;  // End of program
}
