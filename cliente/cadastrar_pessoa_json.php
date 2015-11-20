<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" integrity="sha512-dTfge/zgoMYpP7QbHy4gWMEGsbsdZeCXz7irItjcC3sPUFtf0kuFbDz/ixG7ArTxmDjLXDmezHubeNikyKGVyQ==" crossorigin="anonymous">
<title>Cadastrar Pessoas no WebService</title>
</head>
<body>
<h1>Cadastro de Pessoa JSON</h1>

<form method="post">
Nome: <input type="text" name="nome"><br>
Idade: <input type="text" name="idade"><br>
Peso: <input type="text" name="peso"><br>
<input type="submit">
</form>

<?php

class pessoa {
	public $nome = "";
	public $idade = 0;
	public $peso = 0;
}

if (isset($_POST["nome"])) {
	$pessoa = new pessoa();
	$pessoa->nome = $_POST["nome"];
	$pessoa->peso = doubleval($_POST["peso"]);
	$pessoa->idade = intval($_POST["idade"]);
	$json = json_encode($pessoa);

	$post = file_get_contents('http://localhost:18080/pessoa/inserir/json',null,stream_context_create(array(
    'http' => array(
        'protocol_version' => 1.1,
        'user_agent'       => 'PHPBolado',
        'method'           => 'POST',
        'header'           => "Content-type: application/json\r\n".
                              "Connection: close\r\n" .
                              "Content-length: " . strlen($json) . "\r\n",
        'content'          => $json,
    ),
	)));

	if (!$post) {
		echo "Falhou ao inserir!" . $post;
	} else {
		echo "Inserido no banco " . $post;
	}
}

?>

</body>
</html>