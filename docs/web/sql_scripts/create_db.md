```sql
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema iot
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `iot` ;

-- -----------------------------------------------------
-- Schema iot
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `iot` DEFAULT CHARACTER SET utf8 ;
USE `iot` ;

-- -----------------------------------------------------
-- Table `iot`.`Appointment`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `iot`.`Appointment` (
`appointment_id` INT NOT NULL AUTO_INCREMENT,
`date_time_appointment` DATETIME NOT NULL,
`name` VARCHAR(45) NOT NULL,
PRIMARY KEY (`appointment_id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `iot`.`Sensor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `iot`.`Sensor` (
`sensor_id` INT NOT NULL AUTO_INCREMENT,
`light` INT NOT NULL,
`date_time` DATE NOT NULL,
PRIMARY KEY (`sensor_id`))
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
```
