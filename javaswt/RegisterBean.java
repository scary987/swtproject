package javaswt;
public class RegisterBean{
    public int Sessionid; 
    public String Username; 
    public String Password; 
    public String Vorname; 
    public String Nachname; 
    public String Date;  

	public RegisterBean(){}

	public int getSessionid() {
		return this.Sessionid;
	}

	public void setSessionid(int Sessionid) {
		this.Sessionid = Sessionid;
	}

	public String getUsername() {
		return this.Username;
	}

	public void setUsername(String Username) {
		this.Username = Username;
	}

	public String getPassword() {
		return this.Password;
	}

	public void setPassword(String Password) {
		this.Password = Password;
	}

	public String getVorname() {
		return this.Vorname;
	}

	public void setVorname(String Vorname) {
		this.Vorname = Vorname;
	}

	public String getNachname() {
		return this.Nachname;
	}

	public void setNachname(String Nachname) {
		this.Nachname = Nachname;
	}

	public String getDate() {
		return this.Date;
	}

	public void setDate(String Date) {
		this.Date = Date;
	}
}