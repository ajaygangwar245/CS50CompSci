-- Keep a log of any SQL queries you execute as you solve the mystery.

-- To read crime scene reports
SELECT description
FROM crime_scene_reports
WHERE day = 28
AND month = 7
AND street = 'Humphrey Street';

-- To read interviews of the witnesses
SELECT name, transcript
FROM interviews
WHERE day = 28
AND month = 7;

-- To check the bakery security logs as mentioned by first witness
SELECT *
FROM bakery_security_logs
WHERE day = 28
AND month = 7
AND activity = 'exit'
AND hour = 10
AND minute < 25;

-- To check the ATM transactions as mentioned by second witness
SELECT *
FROM atm_transactions
WHERE day = 28
AND month = 7
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- To check the phone call details as mentioned by third witness
SELECT *
FROM phone_calls
WHERE day = 28
AND month = 7
AND duration < 60;

-- To check flight details from Fiftyville for next day order by time
SELECT *
FROM flights
WHERE day = 29
AND month = 7
AND origin_airport_id = (
    SELECT id
    FROM airports
    WHERE city = 'Fiftyville'
)
ORDER BY hour;

-- To check city where theif escaped
SELECT city
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE day = 29
    AND month = 7
    AND origin_airport_id = (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    )
    ORDER BY hour
    LIMIT 1
);

-- To check for the passengers who board the flight
SELECT *
FROM passengers
WHERE flight_id = (
    SELECT id
    FROM flights
    WHERE day = 29
    AND month = 7
    AND origin_airport_id = (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    )
    ORDER BY hour
    LIMIT 1
);

-- To check details of people who board the flight
SELECT *
FROM people
WHERE passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = (
        SELECT id
        FROM flights
        WHERE day = 29
        AND month = 7
        AND origin_airport_id = (
            SELECT id
            FROM airports
            WHERE city = 'Fiftyville'
        )
        ORDER BY hour
        LIMIT 1
    )
);

-- To match license plate of people who left bakery within 10 minutes
SELECT *
FROM people
WHERE passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = (
        SELECT id
        FROM flights
        WHERE day = 29
        AND month = 7
        AND origin_airport_id = (
            SELECT id
            FROM airports
            WHERE city = 'Fiftyville'
        )
        ORDER BY hour
        LIMIT 1
    )
)
AND license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND month = 7
    AND activity = 'exit'
    AND hour = 10
    AND minute < 25
);

-- To check bank accounts of people withdrawn money from legget street
SELECT name
FROM people
WHERE id IN (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE day = 28
        AND month = 7
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
);

-- To catch the theif
SELECT name
FROM people
WHERE passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = (
        SELECT id
        FROM flights
        WHERE day = 29
        AND month = 7
        AND origin_airport_id = (
            SELECT id
            FROM airports
            WHERE city = 'Fiftyville'
        )
        ORDER BY hour
        LIMIT 1
    )
)
AND license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND month = 7
    AND activity = 'exit'
    AND hour = 10
    AND minute < 25
)
AND name IN (
    SELECT name
    FROM people
    WHERE id IN (
        SELECT person_id
        FROM bank_accounts
        WHERE account_number IN (
            SELECT account_number
            FROM atm_transactions
            WHERE day = 28
            AND month = 7
            AND atm_location = 'Leggett Street'
            AND transaction_type = 'withdraw'
        )
    )
)
AND phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE day = 28
    AND month = 7
    AND duration < 60
);

-- To catch the accomplice of theif
SELECT name
FROM people
WHERE phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE duration < 60
    AND day = 28
    AND month = 7
    AND caller IN (
        SELECT phone_number
        FROM people
        WHERE passport_number IN (
            SELECT passport_number
            FROM passengers
            WHERE flight_id = (
                SELECT id
                FROM flights
                WHERE day = 29
                AND month = 7
                AND origin_airport_id = (
                    SELECT id
                    FROM airports
                    WHERE city = 'Fiftyville'
                )
                ORDER BY hour
                LIMIT 1
            )
        )
        AND license_plate IN (
            SELECT license_plate
            FROM bakery_security_logs
            WHERE day = 28
            AND month = 7
            AND activity = 'exit'
            AND hour = 10
            AND minute < 25
        )
        AND name IN (
            SELECT name
            FROM people
            WHERE id IN (
                SELECT person_id
                FROM bank_accounts
                WHERE account_number IN (
                    SELECT account_number
                    FROM atm_transactions
                    WHERE day = 28
                    AND month = 7
                    AND atm_location = 'Leggett Street'
                    AND transaction_type = 'withdraw'
                )
            )
        )
        AND phone_number IN (
            SELECT caller
            FROM phone_calls
            WHERE day = 28
            AND month = 7
            AND duration < 60
        )
    )
);
