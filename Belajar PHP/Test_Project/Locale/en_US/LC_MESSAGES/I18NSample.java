import java.util.*;

public class I18NSample {

    static public void main(String[] arch) {

        String language;
        String country;

        if (arch.length != 2) {
            language = new String("en");
            country = new String("US");
        } 

        else {
            language = new String(arch[0]);
            country = new String(arch[1]);
        }

        Locale currentLocale;
        ResourceBundle messages;

        currentLocale = new Locale(language, country);

        messages = ResourceBundle.getBundle("MessagesBundle", currentLocale);
        System.out.println(messages.getString("greetings"));
        System.out.println(messages.getString("inquiry"));
        System.out.println(messages.getString("farewell"));
    }
}
