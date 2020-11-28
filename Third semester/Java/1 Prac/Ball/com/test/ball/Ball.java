package com.test.ball;

import java.lang.*;
import java.util.HashMap;
import java.util.Map;

public class Ball {

    public int size;
    public String model;
    public String color;
    public double weight;

    public Ball(int size, String model, String color, double weight) {
        this.size = size;
        this.model = model;
        this.color = color;
        this.weight = weight;
    }

    public Map<String, Object> getInfo() { //It's really more convenient
        Map<String, Object> dict = new HashMap<String, Object>();
        dict.put("size", this.size);
        dict.put("model", this.model);
        dict.put("color", this.color);
        dict.put("weight", this.weight);

        return dict;
    }

    public String toString() {
        return String.format("Size: %d\nModel: %s\nColor: %s\nWeight: %.2f",
                this.size,
                this.model,
                this.color,
                this.weight);
    }

    public String getLightness(){
        if (this.weight > 1.0 && this.weight < 5.0)
            return "Light";
        if (this.weight > 5.0 && this.weight < 10.0)
            return "Medium lightness";
        return "Heavy";
    }

}
