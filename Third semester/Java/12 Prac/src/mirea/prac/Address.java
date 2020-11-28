package mirea.prac;

public class Address {
    public String country;
    public String region;
    public String city;
    public String street;
    public String house;
    public String bulk;
    public int apartment;

    public Address(String country, String region, String city, String street, String house, String bulk, int apartment){
        this.country = country;
        this.region = region;
        this.city = city;
        this.street = street;
        this.house = house;
        this.bulk = bulk;
        this.apartment = apartment;
    }

    public Address(String raw, String separator){
        if (separator == null)
            separator = ",";
        parse(raw, separator);
    }

    public Address(){

    }

    private void parse(String raw, String separator){
        String [] temp;
        raw = raw.strip();

        temp = raw.split(separator);
        this.country = temp[0];
        this.region = temp[1];
        this.city = temp[2];
        this.street = temp[3];
        this.house = temp[4];
        this.bulk = temp[5];
        this.apartment = Integer.parseInt(temp[6]);

    }

    @Override
    public String toString() {
        return "Address{" +
                "country='" + country + '\'' +
                ", region='" + region + '\'' +
                ", city='" + city + '\'' +
                ", street='" + street + '\'' +
                ", house='" + house + '\'' +
                ", bulk='" + bulk + '\'' +
                ", apartment=" + apartment +
                '}';
    }
}
