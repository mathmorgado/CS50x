-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get information from the case --
SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28 AND description LIKE "%duck%";

-- There were 3 interviews with witnesses to the robbery --

-- Get information from the interviews witnesses --
SELECT id, name, transcript FROM interviews WHERE month = 7 AND day = 28 AND transcript LIKE "%bakery%";

-- The thief made a call of less than a minute to someone after leaving the bakery, asking them to buy a ticket for the first flight out of Fiftyville. Sometime within ten minutes of the theft, the thief got into a car in the parking lot and went to the Leggett Street ATM to withdraw money--

-- Get information from phone logs in 07/28/2021 with less than 1 minute duration --
SELECT caller.id, caller.name AS caller, receiver.id, receiver.name AS receiver
 FROM phone_calls
JOIN people caller
  ON phone_calls.caller = caller.phone_number
JOIN people receiver
  ON phone_calls.receiver = receiver.phone_number
WHERE month = 7 AND day = 28 AND year = 2021 AND duration < 60;

--                       Suspects                     --

--       +--------+---------+--------+------------+
--       |   id   | caller  |   id   |  receiver  |
--       +--------+---------+--------+------------+
--       | 398010 | Sofia   | 567218 | Jack       |
--       | 560886 | Kelsey  | 251693 | Larry      |
--       | 686048 | Bruce   | 864400 | Robin      |
--       | 560886 | Kelsey  | 626361 | Melissa    |
--       | 449774 | Taylor  | 250277 | James      |
--       | 514354 | Diana   | 847116 | Philip     |
--       | 907148 | Carina  | 712712 | Jacqueline |
--       | 395717 | Kenny   | 953679 | Doris      |
--       | 438727 | Benista | 484375 | Anna       |
--       +--------+---------+--------+------------+


-- Get license plate information from the bakery's security records --
SELECT sus.id, sus.name AS sus
  FROM bakery_security_logs AS bsl
 JOIN people AS sus
  ON  bsl.license_plate = sus.license_plate
 WHERE month = 7 AND day = 28 AND year = 2021 AND hour = 10 and minute <= 25 and activity = "exit";

--                                New Thief Suspects                            --

--       made a phone call and left the bakery parking lot between 10:15 and 10:25

--                               +--------+---------+
--                               |   id   |   sus   |
--                               +--------+---------+
--                               | 686048 | Bruce   |
--                               | 398010 | Sofia   |
--                               | 514354 | Diana   |
--                               +--------+---------+


-- Get information from the Leggett Street ATM --
SELECT sus.id, sus.name, atm.amount
  FROM atm_transactions AS atm
 JOIN bank_accounts AS ba
  ON ba.account_number = atm.account_number
 JOIN people AS sus
  ON ba.person_id = sus.id
 WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

--                                             Thief Suspects                             --

--       made a phone call, left the bakery parking lot between 10:15 and 10:25, went to the ATM to withdraw money

--                                     +--------+---------+--------+
--                                     |   id   |  name   | amount |
--                                     +--------+---------+--------+
--                                     | 686048 | Bruce   | 50     |
--                                     | 514354 | Diana   | 35     |
--                                     +--------+---------+--------+


-- Get information on the first flight out of Fiftyville on 07/29/2021 --
SELECT thief.id, thief.name, airp1.city, airp2.city
  FROM flights
 JOIN airports AS airp1
  ON airp1.id = flights.origin_airport_id
 JOIN airports as airp2
  ON airp2.id = flights.destination_airport_id
 JOIN passengers AS sus
  ON sus.flight_id = flights.id
 JOIN people AS thief
  ON thief.passport_number = sus.passport_number
 WHERE month = 7 AND day = 29 AND year = 2021
 ORDER BY hour ASC LIMIT 10;

--                                                  Thief, accomplice and city                           --

--   made a phone call, left the bakery parking lot between 10:15 and 10:25, went to the ATM to withdraw money and took the first flight out of the city.

--                                                   Bruce | Robin | New York
