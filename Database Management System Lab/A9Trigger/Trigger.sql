==================================================================================================

ACTUAL PROBLEM STATEMENT CODE
==================================================================================================
1) before->delete

DELIMITER $$
CREATE TRIGGER before_book_delete_try1
BEFORE DELETE ON books
FOR EACH ROW
BEGIN
INSERT INTO lib_audit
SET action ='delete',
accno=OLD.accno,
title=OLD.title,
author=OLD.author,
publisher=OLD.publisher,
count=OLD.count;
END$$

DELIMITER ;

2) after-> update

DELIMITER $$
CREATE TRIGGER after_book_update
AFTER UPDATE ON books
FOR EACH ROW
BEGIN
INSERT INTO lib_audit
SET action ='update',
accno=NEW.accno,
title=NEW.title,
author=NEW.author,
publisher=NEW.publisher,
count=NEW.count;
END$$


DELIMITER ;



	


