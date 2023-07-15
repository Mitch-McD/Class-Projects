package SecureState;

public class EncryptedString {
    private String _string;
    public EncryptedString(String s) { _string = s; }
    public String getString() { return _string; }
    @Override
    public boolean equals(Object o) { 
        // If the object is compared with itself then return true   
        if (o == this) { 
            return true; 
        }  
        /* Check if o is an instance of Complex or not 
          "null instanceof [type]" also returns false */
        if (!(o instanceof EncryptedString)) { 
            return false; 
        }          
        // typecast o to Complex so that we can compare data members  
        EncryptedString es = (EncryptedString) o; 
          
        // Compare the data members and return accordingly  
        return _string.equals(es.getString()); 
    } 

}
