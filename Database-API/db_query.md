#DB Query

##Connaitre le nombre de résultats d'une requète
$num_of_nodes = db_query('SELECT nid FROM {node}')->rowCount(); 
