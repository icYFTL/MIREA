package mirea.prac;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws Exception {
        Person person = new Person("семен", "семенов", "семенович");
        System.out.println(person.result());

        Person person1 = new Person();
        person1.name = "test";
        System.out.println(person1.result());
        String[] shirts = new String[11];
        shirts[0] = "S001,Black Polo Shirt,Black,XL";
        shirts[1] = "S002,Black Polo Shirt,Black,L";
        shirts[2] = "S003,Blue Polo Shirt,Blue,XL";
        shirts[3] = "S004,Blue Polo Shirt,Blue,M";
        shirts[4] = "S005,Tan Polo Shirt,Tan,XL";
        shirts[5] = "S006,Black T-Shirt,Black,XL";
        shirts[6] = "S007,White T-Shirt,White,XL";
        shirts[7] = "S008,White T-Shirt,White,L";
        shirts[8] = "S009,Green T-Shirt,Green,S";
        shirts[9] = "S010,Orange T-Shirt,Orange,S";
        shirts[10] = "S011,Maroon Polo Shirt,Maroon,S";

        ArrayList<Shirt> newShirts = new ArrayList<>();

        for (var _s : shirts) {
            newShirts.add(new Shirt(_s, null));
        }

        for (var _s : newShirts) {
            System.out.println(_s);
        }

        CellNumber CN1 = new CellNumber("+79167031940");
        System.out.println(CN1.formatted());

        CellNumber CN2 = new CellNumber("89167031940");
        System.out.println(CN2.formatted());

        try {
            CellNumber CN3 = new CellNumber("32431432");
            System.out.println(CN3.formatted());
        } catch (Exception ex) {
            System.out.println(ex);
        }

    }
}
