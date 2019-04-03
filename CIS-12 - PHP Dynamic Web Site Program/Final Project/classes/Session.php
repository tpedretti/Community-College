<?php
class Session {
    public static function start() {
        session_start();
    }
    public static function logout() {
        session_start();
        $_SESSION['userName'] = '';
        $_SESSION['loggedin'] = FALSE;
        session_destroy();
    }
    public static function login($userName) {
        session_start();
        $_SESSION['userName'] = $userName;
        $_SESSION['loggedin'] = TRUE;
        session_commit();
    }
    public static function isLoggedIn() {
        return $_SESSION['loggedin'];
    }
}
?>
