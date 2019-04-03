-- phpMyAdmin SQL Dump
-- version 4.0.2
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1:3306

-- Generation Time: Jun 04, 2013 at 02:19 AM
-- Server version: 5.5.31
-- PHP Version: 5.4.15

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `lollfg`
--
CREATE DATABASE IF NOT EXISTS `lollfg` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `lollfg`;

-- --------------------------------------------------------

--
-- Table structure for table `userposts`
--

CREATE TABLE `userposts` (
  `dbID` int(11) NOT NULL AUTO_INCREMENT,
  `summonerName` varchar(128) NOT NULL,
  `gameType` varchar(128) NOT NULL,
  `userComments` varchar(255) NOT NULL,
  `timeCreated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`dbID`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `userposts`
--

INSERT INTO `userposts` (`dbID`, `summonerName`, `gameType`, `userComments`, `timeCreated`) VALUES
(4, 'htgfhgfhj456b', '56b47575', '5647bn567nm68,m967', '2013-06-02 00:26:59'),
(3, 'fsdf', 'gsfdg', 'gsfdg', '2013-06-01 23:53:15'),
(5, 'gfdgfdg', 'Ranked5v5', 'fhgfdhggfhf', '2013-06-02 01:27:35');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(128) NOT NULL,
  `password` varchar(128) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`ID`, `username`, `password`) VALUES
(1, 'Admin', '202cb962ac59075b964b07152d234b70');

-- --------------------------------------------------------

--
-- Table structure for table `userseu`
--

CREATE TABLE `userseu` (
  `dbID` int(11) NOT NULL AUTO_INCREMENT,
  `summonerName` varchar(128) NOT NULL,
  `gameType` varchar(128) NOT NULL,
  `userComments` varchar(255) NOT NULL,
  `timeCreated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`dbID`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `userseu`
--

INSERT INTO `userseu` (`dbID`, `summonerName`, `gameType`, `userComments`, `timeCreated`) VALUES
(1, 'EU USER 1', 'Normal 5v5', 'Normal Normal Ranked 5v5 Normal Normal Normal Normal Normal ', '2013-05-20 19:58:35'),
(2, 'EU USER 2', 'Ranked 3v3', 'Normal Normal Normal Normal Normal Normal ', '2013-05-20 19:58:35'),
(3, 'Sgbfdg', 'Normal5v5', 'gfdsgfdgfdhg', '2013-06-02 01:59:18'),
(4, '123456789', 'Ranked5v5', 'fsdfdgdfgsd', '2013-06-03 02:38:13'),
(5, '54645654', 'Ranked5v5', '54654654645', '2013-06-04 00:42:54');

-- --------------------------------------------------------

--
-- Table structure for table `usersna`
--

CREATE TABLE `usersna` (
  `dbID` int(11) NOT NULL AUTO_INCREMENT,
  `summonerName` varchar(128) NOT NULL,
  `gameType` varchar(128) NOT NULL,
  `userComments` varchar(255) NOT NULL,
  `timeCreated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`dbID`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `usersna`
--

INSERT INTO `usersna` (`dbID`, `summonerName`, `gameType`, `userComments`, `timeCreated`) VALUES
(1, 'NA USER 1', 'Normal 3v3', 'fjkosejkfsjk fnsdjkfnjk n jk jk Normal', '2013-05-20 19:57:54'),
(2, 'NA USER 2', 'Normal 5v5', 'Normal Normal Normal Normal Normal Normal Normal Normal ', '2013-05-20 19:57:54'),
(3, 'Testing123', 'Normal5v5', 'I need this!', '2013-06-02 01:35:20'),
(4, 'GFDGFDGDS', 'DuoRanked', 'gfdsgfdsgfdgfd', '2013-06-02 20:19:39'),
(5, 'in Class', 'Normal3v3', 'kldgnkjdfnkjfd', '2013-06-04 00:37:56');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
