<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" integrity="sha512-dTfge/zgoMYpP7QbHy4gWMEGsbsdZeCXz7irItjcC3sPUFtf0kuFbDz/ixG7ArTxmDjLXDmezHubeNikyKGVyQ==" crossorigin="anonymous">
<title>Pessoas Cadastradas no WebService</title>
</head>
<body>
<h1>Pessoas JSON</h1>
<?php
    $link = "http://localhost:18080/pessoas/json";
    $file = file_get_contents($link);
    $json = json_decode($file, true);
    echo "<table border=\"1\" class=\"table table-hover\">";
    echo "<th style=\"width:50px;\">Codigo</th>";
    echo "<th style=\"width:300px;\">Nome</th>";
    echo "<th style=\"width:50px;\">Idade</th>";
    echo "<th style=\"width:50px;\">Peso</th>";
    
    foreach ($json["pessoas"] as $pessoa) {
        echo "<tr>";
        echo "<td>" . $pessoa["id"] . "</td>";
        echo "<td>" . $pessoa["nome"] . "</td>";
        echo "<td>" . $pessoa["idade"] . "</td>";
        echo "<td>" . $pessoa["peso"] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
    
?>
</body>
</html>
