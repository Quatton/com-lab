import { readFileSync } from "fs";
import { exit } from "process";
import { Resend } from "resend";

const resend = new Resend(Bun.env.RESEND_API_KEY);

const extension: Record<string, string> = {
  c: "C",
  scm: "S",
};

const input = prompt("Which Kadai?");

if (!input) exit();

if (input === "a") {
  for (let i = 36; i <= 37; i++) void submitFromInput(`kadai${i}.c`);
} else {
  void submitFromInput(input);
}

async function submitFromInput(input: string) {
  const sp = input.split(" ");
  const f = sp.shift();
  const [filename, ext] = f!.split(".");
  if (!(ext in extension)) exit();

  const s = sp.shift();
  const section = s ? s.toUpperCase() : extension[ext];

  const [_, num] = filename.split("kadai");

  const file = readFileSync(`../${section}/kadai${num}/kadai${num}.${ext}`);
  const attachments = [
    {
      filename: `kadai${num}.${ext}`,
      content: file,
    },
  ];

  try {
    const report = readFileSync(`../${section}/kadai${num}/report.txt`);
    attachments.push({
      filename: `report.txt`,
      content: report,
    });
  } catch (err) {
    // no report it's ok
  }

  try {
    const data = await resend.emails.send({
      from: Bun.env.FROM!,
      to: "isutbe2023@gmail.com",
      cc: Bun.env.CC!,
      subject: `${section}${num} ${Bun.env.DETAIL}`,
      text: `This is an automated submission email. Please contact ${Bun.env
        .CC!}.`,
      attachments,
    });

    console.log(data.id);
  } catch (e) {
    console.log(e);
  }
}
