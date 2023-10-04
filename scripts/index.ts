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
  for (let i = 28; i <= 32; i++) void submitFromInput(`kadai${i}.c`);
} else {
  void submitFromInput(input);
}

async function submitFromInput(input: string) {
  const [filename, ext] = input.split(".");
  if (!(ext in extension)) exit();

  const [_, num] = filename.split("kadai");

  const file = readFileSync(`../kadai${num}/kadai${num}.${ext}`);
  const attachments = [
    {
      filename: `kadai${num}.${ext}`,
      content: file,
    },
  ];

  try {
    const report = readFileSync(`../kadai${num}/report.txt`);
    attachments.push({
      filename: `report.txt`,
      content: report,
    });
  } catch (err) {
    // no report it's ok
  }

  try {
    const data = await resend.emails.send({
      from: "Nutchanon TAECHASUK <n.taechasuk@quattonary.com>",
      to: "atomicatives@gmail.com",
      cc: "taechasuk-nutchanon048@g.ecc.u-tokyo.ac.jp",
      subject: `${extension[ext]}${num} 理学部情報科学科 J4220661 タエチャスクナッチャノン`,
      text: "This is an automated submission email. Please contact taechasuk-nutchanon048@g.ecc.u-tokyo.ac.jp.",
      attachments,
    });

    console.log(data.id);
  } catch (e) {
    console.log(e);
  }
}
