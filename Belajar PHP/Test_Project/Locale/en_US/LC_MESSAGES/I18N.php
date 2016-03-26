<?php
// I18N support information here
$language = "en_US";
putenv("LANG=".$language);
setlocale(LC_ALL, $language);

// Set the text domain as "messages"
$domain = "messages";
binddtextdomain($domain, "Locale");
textdomain($domain);

echo gettext("This is a text string");
?>