package mirea.prac;


import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CellNumber {
    private String raw;
    public String number;
    public String region_code;


    public CellNumber(String raw) throws Exception {
        this.raw = raw;
        this.beautify();
    }

    public void beautify() throws Exception {
        Pattern pattern = Pattern.compile("^((\\+7)?8?)([0-9]{10})$");
        Matcher matcher = pattern.matcher(this.raw);

        if (matcher.find()) {
            this.number = matcher.group(3);
            this.region_code = matcher.group(1);
        }
        else
            throw new Exception("Invalid number passed");
    }

    public String formatted() {
        char[] first_three = new char[3];
        char[] second_three = new char[3];
        char[] third_four = new char[4];
        this.number.getChars(0, 3, first_three, 0);
        this.number.getChars(3, 6, second_three, 0);
        this.number.getChars(6, 10, third_four, 0);
        return String.format("%s%s-%s-%s",
                this.region_code,
                String.copyValueOf(first_three),
                String.copyValueOf(second_three),
                String.copyValueOf(third_four)
        );
    }

    @Override
    public String toString() {
        return "CellNumber{" +
                "raw='" + raw + '\'' +
                ", number='" + number + '\'' +
                ", region_code='" + region_code + '\'' +
                '}';
    }
}
