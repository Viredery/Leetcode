public class Solution {
    public String intToRoman(int num) {
        String result = new String();
        int value = 0, number = num;
        if ((value = number / 1000) != 0) {
            switch (value) {
                case 1:
                    result = result.concat("M");break;
                case 2:
                    result = result.concat("MM");break;
                case 3:
                    result = result.concat("MMM");break;
                default:
                    break;
            }
        }
        number = number % 1000;
        if ((value = number / 100) != 0) {
            switch (value) {
                case 1:
                    result = result.concat("C");break;
                case 2:
                    result = result.concat("CC");break;
                case 3:
                    result = result.concat("CCC");break;
                case 4:
                    result = result.concat("CD");break;
                case 5:
                    result = result.concat("D");break;
                case 6:
                    result = result.concat("DC");break;
                case 7:
                    result = result.concat("DCC");break;
                case 8:
                    result = result.concat("DCCC");break;
                case 9:
                    result = result.concat("CM");break;
                default:
                    break;
            }
        }
        number = number % 100;
        if ((value = number / 10) != 0) {
            switch (value) {
                case 1:
                    result = result.concat("X");break;
                case 2:
                    result = result.concat("XX");break;
                case 3:
                    result = result.concat("XXX");break;
                case 4:
                    result = result.concat("XL");break;
                case 5:
                    result = result.concat("L");break;
                case 6:
                    result = result.concat("LX");break;
                case 7:
                    result = result.concat("LXX");break;
                case 8:
                    result = result.concat("LXXX");break;
                case 9:
                    result = result.concat("XC");break;
                default:
                    break;
            }
        }
        number = number % 10;
        switch (number) {
            case 1:
                result = result.concat("I");break;
            case 2:
                result = result.concat("II");break;
            case 3:
                result = result.concat("III");break;
            case 4:
                result = result.concat("IV");break;
            case 5:
                result = result.concat("V");break;
            case 6:
                result = result.concat("VI");break;
            case 7:
                result = result.concat("VII");break;
            case 8:
                result = result.concat("VIII");break;
            case 9:
                result = result.concat("IX");break;
            default:
                break;
        }
        return result;
    }
}