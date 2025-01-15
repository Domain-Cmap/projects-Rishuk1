public class Sample {

public static void main(String[] args) {
  
    String str = "aabccdeff";
    Map<Character, Boolean> charCountMap = new  HashMap<Character, Boolean>();

    for(int i=0; i<str.length(); i++) {

        char c = str.charAt(i);

        if(charCountMap.containsKey(c)) {

            charCountMap.put(c, false);        
        }
        else {

            charCountMap.put(c, true);         
        }

    } 

    for(int i=0; i<str.length(); i++) {

        char c = str.charAt(i);
        boolean bool = (boolean) charCountMap.get(c);

        if(bool) {

            System.out.println("first non-repeating character is: " + c);
            break;
        }

    } 
}
}